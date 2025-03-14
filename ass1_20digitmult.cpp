#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string multiply(string s1, string s2){

    int len1 = s1.length();
    int len2 = s2.length();

    int n1;
    int n2;

    int i_n1=0;
    int i_n2=0;

    int result[len1+len2];
    memset(result, 0, sizeof(result));
    int sum;
    int carry;
    if(len1==0 || len2==0){
        return "0";
    }

    for (int i = len1-1; i >= 0; i--)
    {
        n1= s1[i] - '0';  // convert string to equivalent number  '0' == 48
        carry=0;
        i_n2=0;
        
        for (int j = len2-1; j >= 0; j--){
            n2 = s2[j] - '0';
            sum =n1*n2 + result[i_n1+i_n2] + carry;

            result[i_n1+i_n2] = sum%10;
            carry = sum/10;
            i_n2+=1;
        }
       

        if (carry>0){
            result[i_n1+i_n2] += carry;
        }
        i_n1+=1;
        
    }
    string ans="";
    int t = len1+len2-1;
    while(t>=0 && result[t]==0){
        t-=1;
    }

    if(t==-1){
        return "0";
    }

    while (t >= 0)
    {
        ans += to_string(result[t--]);
    }
    
    return ans;

}

int main(){
    string s1 = "456032659878425";
    string s2 = "234";
    string ans = multiply(s1,s2);
    cout<<"Answer : " << ans<<endl;
}