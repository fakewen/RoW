#include <iostream>
#include <vector>
#include <map>
#include <utility>      // std::pair, std::get
using namespace std;

//6:54 s
//9:20 e
//1

inline int Factorial(int x) {
    return (x == 1 ? x : x * Factorial(x - 1));
}

int main(void)
{
    //Success
    string s;
    cin>>s;
    cout<<s;
    
    map<char,int> c2index;//c1 e2 s3 u4
    map<char,int> c2amount;//c2 e1 s3 u1 //std::map will sort its elements by keys
    for(int i=0;i<s.size();i++){
        c2amount[s[i]]++;
    }
    cout<<endl;
    int tmp_index=1;
    for(auto it:c2amount){
        cout<<get<0>(it)<<get<1>(it)<<" ";
        c2index[get<0>(it)]=tmp_index++;
    }
    
    cout<<endl;
    for(auto it:c2index){
        cout<<get<0>(it)<<get<1>(it)<<" ";
    }
    
    
    int ans=0;
    int n=s.size();
    
    for(int i=0;i<n-1;i++){
        int LessThanCur=0;
        map<char,int> lessC;
        lessC[s[i]]++;
        for(int j=i+1;j<n;j++){
            lessC[s[j]]++;
            if(c2index[s[j]]<c2index[s[i]]){
                LessThanCur++;
                
            }
        }
        int dup=1;
        for(auto it:lessC){
            cout<<endl<<"@dup"<<get<0>(it)<<"#"<<get<1>(it);
            dup*=Factorial(get<1>(it));
        }
        cout<<endl<<LessThanCur<<"*"<<n-i-1<<"!/"<<dup;
        ans += LessThanCur * Factorial(n-i-1)/dup;
    }
    ans+=1;
    cout<<endl<<"Rank of Word:"<<ans<<endl;
    //for quizk
    return 0;
}
