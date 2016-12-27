#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
class node {
public:
    int color=0;
    int number;
    int checked=0;
    vector <node*> connected_nodes;
    vector <int> colors={0,1};
    node(int);
};

vector <node*> nodes;
bool flag=0;

node::node(int n){
    number=n;
}

void connect(int n, int m) {
    nodes[m]->connected_nodes.push_back(nodes[n]);
    nodes[n]->connected_nodes.push_back(nodes[m]);

}
void set_color(node* nd) {

    if(!(nd->checked==nd->connected_nodes.size())){
        nd->checked++;
        for (int i = 0; i < nd->connected_nodes.size() ; ++i) {
            if(!(nd->checked==nd->connected_nodes.size())) {
               if(nd->color==0){
                   nd->connected_nodes[i]->colors.erase(nd->connected_nodes[i]->colors.begin());
               }
                else{
                   nd->connected_nodes[i]->colors.pop_back();
               }
                if(!(nd->connected_nodes[i]->colors.empty())) {
                    nd->connected_nodes[i]->color=*(min_element(nd->connected_nodes[i]->colors.begin(),nd->connected_nodes[i]->colors.end()));
                    set_color(nd->connected_nodes[i]);
                } else {
                    flag = 1;
                    return;
                }

            }
        }
    }

}

void check() {
        if(flag==1){
            cout<<"NOT BICOLORABLE."<<endl;
        }
        else
            cout<<"BICOLORABLE."<<endl;

        flag=0;
    }


int n,l,m,k;
int main() {
    cin>>n;
    while(n){
        for (int i = 0; i < n ; ++i) {
            nodes.push_back(new node(i));
        }
        cin>>l;
        for (int j = 0; j < l ; ++j) {
            cin >> m >> k;
            connect(m, k);
        }
        nodes[0]->color=0;
        set_color(nodes[0]);
        check();
        nodes.erase(nodes.begin(),nodes.end());
        cin>>n;
    }

    return 0;
}



















