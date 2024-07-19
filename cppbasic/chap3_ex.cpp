#include <iostream>
#include <vector>

using namespace std;

// helper function
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

// sense function
vector<float> sense(vector<float> p, vector<char> world, char z, float p_hit, float p_miss)
{
    vector<float> q(p.size(),0);
    float sum;
    for(int i=0;i<p.size();i++)
    {
        int hit = (z == world[i]);
        q[i] = p[i] * (hit * p_hit + (1-hit) * p_miss);
        sum += q[i];
    }
    for(int i=0;i<q.size();i++) q[i] /= sum;
    // cout<<"Sense: ";
    // print_vec(q);
    return q;
}

//moce function
vector<float> move(vector<float> p, int u, float p_exact, float p_over, float p_under)
{
    vector<float> q(p.size(),0);
    for(int i=0;i<p.size();i++)
    {
        float s = 0;
        if(i-u < 0) s = p_exact * p[(i-u) + p.size()];
        else s = p_exact * p[(i-u) % p.size()];
        if(i-u-1 < 0) s += p_over * p[(i-u-1) + p.size()];
        else s += p_over * p[(i-u-1) % p.size()];
        if(i-u+1 < 0) s += p_under * p[(i-u+1) + p.size()];
        else s += p_under * p[(i-u+1) % p.size()];
        //c と python では%の挙動が違うのでこうしないと配列の不正参照が起こる
        q[i] = s;
    }
    // cout<<"Move : ";
    // print_vec(q);
    return q;
}


int main(void)
{
    vector<float> p(5,0.2);
    vector<char> world{'G','R','R','G','G'};
    vector<char> measurements{'R','G'};
    vector<int> motions{1,1};

    float p_hit = 0.6;
    float p_miss = 0.2;
    float p_exact = 0.8;
    float p_over = 0.1;
    float p_under = 0.1;

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
