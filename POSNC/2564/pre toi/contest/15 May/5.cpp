#include <bits/stdc++.h>

using namespace std;
int ac[100001],ca[100001],ct[100001],tc[100001],at[100001],ta[100001];
int a1[100001],c1[100001],t1[100001],a2[100001],c2[100001],t2[100001];
int dac,dca,dct,dtc,dat,dta;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    string a,b;
    cin>>n>>q>>a>>b;
    a = ' ' + a;
    b = ' ' + b;
    for(int i=1;i<=n;i++){
        ac[i] = ac[i-1]+(a[i]=='A'&&b[i]=='C');
        ca[i] = ca[i-1]+(a[i]=='C'&&b[i]=='A');
        ct[i] = ct[i-1]+(a[i]=='C'&&b[i]=='T');
        tc[i] = tc[i-1]+(a[i]=='T'&&b[i]=='C');
        at[i] = at[i-1]+(a[i]=='A'&&b[i]=='T');
        ta[i] = ta[i-1]+(a[i]=='T'&&b[i]=='A');

        a1[i] = a1[i-1]+(a[i]=='A');
        c1[i] = c1[i-1]+(a[i]=='C');
        t1[i] = t1[i-1]+(a[i]=='T');

        a2[i] = a2[i-1]+(b[i]=='A');
        c2[i] = c2[i-1]+(b[i]=='C');
        t2[i] = t2[i-1]+(b[i]=='T');
    }
    int ans;
    while(q--){
        int l,r;
        cin>>l>>r;
        r++;
        ans = 0;
        if((a1[r]-a1[l]!=a2[r]-a2[l])||
           (c1[r]-c1[l]!=c2[r]-c2[l])||
           (t1[r]-t1[l]!=t2[r]-t2[l])){
            cout<<-1<<endl;
            continue;
        }

        dac = ac[r]-ac[l];
        dca = ca[r]-ca[l];
        dct = ct[r]-ct[l];
        dtc = tc[r]-tc[l];
        dat = at[r]-at[l];
        dta = ta[r]-ta[l];
        int mn;
        mn = min(dac,dca);
        dac -= mn, dca -= mn;
        ans+=mn;
        mn = min(dct,dtc);
        dct -= mn, dtc -= mn;
        ans+=mn;
        mn = min(dat,dta);
        dat -= mn, dta -= mn;
        ans+=mn;

        cout<<ans+2*max(dac,dca)<<endl;
    }
    return 0;
}
