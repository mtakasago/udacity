#include <iostream>
#include <vector>

using namespace std;

// helper function
void print_vec(vector<double> p)
{
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
}
void print_vec(vector<char> p)
{
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
}

// sense function
vector<double> sense(vector<double> p, vector<char> world, char z, double p_hit, double p_miss)
{
    vector<double> q(p.size(),0);
    double sum;
    for(int i=0;i<p.size();i++)
    {
        int hit = (z == world[i]);
        q[i] = p[i] * (hit * p_hit + (1-hit) * p_miss);
        sum += q[i];
    }
    for(int i=0;i<q.size();i++) q[i] = q[i] / sum;
    return q;
}

//moce function
vector<double> move(vector<double> p, int u, double p_exact, double p_over, double p_under)
{
    vector<double> q(p.size(),0.0);
    for(int i=0;i<p.size();i++)
    {
        double s = 0.0;
        if(i-u < 0) s = p_exact * p[(i-u) + p.size()];
        else s = p_exact * p[(i-u) % p.size()];
        if(i-u-1 < 0) s += p_over * p[(i-u-1) + p.size()];
        else s += p_over * p[(i-u-1) % p.size()];
        if(i-u+1 < 0) s += p_under * p[(i-u+1) + p.size()];
        else s += p_under * p[(i-u+1) % p.size()];
        //c と python では%の挙動が違うのでこうしないと配列の不正参照が起こる
        q[i] = s;
    }
    return q;
}


int main(void)
{
    vector<double> p(5,0.2);
    vector<char> world{'G','R','R','G','G'};
    vector<char> measurements{'R','G'};
    vector<int> motions{1,1};

    double p_hit = 0.6;
    double p_miss = 0.2;
    double p_exact = 0.8;
    double p_over = 0.1;
    double p_under = 0.1;

    for(int i=0;i<measurements.size();i++)
    {
        p = sense(p, world, measurements[i], p_hit, p_miss);
        cout<<"Sense: ";
        print_vec(p);
        p = move(p, motions[i], p_exact, p_over, p_under);
        cout<<"Move : ";
        print_vec(p);
        cout<<"====================================================="<<endl;
    }
    return 0;
}
