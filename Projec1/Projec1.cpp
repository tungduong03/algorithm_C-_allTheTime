#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> timeVector;
vector<int> date(730000,0);
vector<int> allPeople;
int cnt=0;

struct Person{
    int code, fa_code,mo_code,region_code;
    char is_alive;
    string dat_of_birth;
};
vector<Person> myPerson;
bool comparePerson(const Person& a, const Person& b) {
    return a.code < b.code;
}

int ConvertPerson(string date) {
    istringstream iss(date);
    int year, month, day;
    char dash1, dash2;
    iss>>year>>dash1>>month>>dash2>>day;
    return (year-1000)*365+ (month-1)*30+day-1;
}

int max_depth(int a) {
    if (myPerson[a-1].fa_code == 0 && myPerson[a-1].mo_code == 0) return 0;
    else if (myPerson[a-1].fa_code == 0) return 1 + max_depth(myPerson[a-1].mo_code);
    else if (myPerson[a-1].mo_code == 0) return 1 + max_depth(myPerson[a-1].fa_code);
    else return 1 + max(max_depth(myPerson[a-1].mo_code), max_depth(myPerson[a-1].fa_code));
}

struct VERTEX{
    vector<int> adjacent;
    int degree=0;
    void Insert(int a){
        for(int tmp: this->adjacent){
            if(tmp==a) return;
        }
        this->adjacent.push_back(a);
        ++(this->degree);
    }
};
vector<VERTEX> vertex;
void InsertVertex(int a, int f, int m){
    if(f!=0){
        vertex[a].Insert(f);
        vertex[f].Insert(a);
    }
    if(m!=0){
        vertex[a].Insert(m);
        vertex[m].Insert(a);
    }
    return;
}
void initVertex(){
    vertex.resize(myPerson.size()+1);
    for(auto i: myPerson){
        InsertVertex(i.code, i.fa_code, i.mo_code);
    }
}
bool comparevertex(int a, int b){
    if(vertex[a].degree == vertex[b].degree) return a<b;
    return vertex[a].degree < vertex[b].degree;
}
//Hàm xóa phần tử trong vector allPeople
void Delete(int p) {
    auto it = find(allPeople.begin(), allPeople.end(), p);
    if (it != allPeople.end()) {
        // Di chuyển các phần tử sau phần tử cần xóa lên
        for (auto next = it + 1; next != allPeople.end(); ++it, ++next) {
            *it = std::move(*next);
        }
        allPeople.pop_back();
    }
    //cập nhật lại bậc cảu các đỉnh kề với p
    for(int i :vertex[p].adjacent){
        vertex[i].degree--;
    }
}

int main(){

    freopen("Projec1.inp","r",stdin);
    string type;
    Person a;

    while(true){
        getline(cin, type);
        if(type=="*")break;
        istringstream iss(type);
        iss >> a.code >> a.dat_of_birth >> a.fa_code >> a.mo_code >> a.is_alive >> a.region_code;
        date[ConvertPerson(a.dat_of_birth)]++;
        myPerson.push_back(a);
        allPeople.push_back(a.code);
    }

    sort(myPerson.begin(), myPerson.end(), comparePerson);
    for(int i=1; i<730000; ++i) date[i]=date[i]+date[i-1];
    initVertex();
    sort(allPeople.begin(), allPeople.end(), comparevertex);


    do {
            cin>>type;
        if(type=="NUMBER_PEOPLE") cout<<myPerson.size()<<'\n';
        if(type=="NUMBER_PEOPLE_BORN_AT"){
            string tmp;
            cin>>tmp;
            cout<<date[ConvertPerson(tmp)] - date[ConvertPerson(tmp)-1] <<'\n';
        }

        if(type=="NUMBER_PEOPLE_BORN_BETWEEN"){
            string d1, d2;
            cin>>d1>>d2;
            cout<<date[ConvertPerson(d2)]-date[ConvertPerson(d1)-1]<<'\n';
        }


        if(type=="MAX_UNRELATED_PEOPLE"){
            int tmp;
            while(!allPeople.empty()){
                tmp=allPeople.front();cnt++;
                Delete(tmp);
                for(int i : vertex[tmp].adjacent) Delete(i);
                sort(allPeople.begin(), allPeople.end(), comparevertex);
            }
            cout<<cnt<<'\n';
        }

        if(type=="MOST_ALIVE_ANCESTOR"){
            int tmp;
            cin>>tmp;
            cout<<max_depth(tmp)<<'\n';
        }
    }
    while (type!="***");
    return 0;
}
