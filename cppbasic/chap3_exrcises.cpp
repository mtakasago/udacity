#include <iostream>
#include <vector>

using namespace std;

vector<float> p(5,0.2);
vector<char> grid{'G','R','R','G','G'};
vector<char> measurements{'R','G'};
vector<int> motions{1,1};

float p_hit = 0.6;
float p_miss = 0.2;
float p_exact = 0.8;
float p_over = 0.1;
float p_under = 0.1;

void print_vec(vector<float> p)
{
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
}
void print_vec(vector<char> p)
{
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
}

vector<float> sense(vector<float> p, char z)
{
    vector<float> q(p.size(),0);
    float sum;
    for(int i=0;i<p.size();i++)
    {
        int hit = (z == grid[i]);
        q[i] = p[i] * (hit * p_hit + (1-hit) * p_miss);
        sum += q[i];
    }
    for(int i=0;i<q.size();i++) q[i] /= sum;
    cout<<"Sense: ";
    print_vec(q);
    return q;
}

vector<float> move(vector<float> p, int u)
{
    vector<float> q(p.size(),0);
    for(int i=0;i<p.size();i++)
    {
        float s = 0;
        s = p_exact * p[(i-u) % p.size()];
        s += p_over * p[(i-u-1) % p.size()];
        s += p_under * p[(i-u+1) % p.size()];
        q[i] = s;
    }
    cout<<"Move : ";
    print_vec(q);
    return q;
}


int main(void)
{
    for(int i=0;i<measurements.size();i++)
    {
        p = sense(p,measurements[i]);
        p = move(p,motions[i]);
        cout<<"p    : ";
        print_vec(p);
        cout<<"====================================================="<<endl;
    }
    return 0;
}
