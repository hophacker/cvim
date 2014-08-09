//带路径压缩的并查集扩展形式
//用于动态维护查询 friend-enemy 型等价类
//维护和查询复杂度略大于 O(1)
//集合元素取值 1..MAXN-1(注意 0 不能用!),默认无关
#define MAXN 100000
#define sig(x) ((x)>0?1:-1)
#define abs(x) ((x)>0?(x):-(x))
#define _ufind_run(x) for(;p[t=abs(x)];x=sig(x)*p[abs(x)],p[t]=sig(p[t])*(p[abs(x)]?p[abs(x)]:abs(p[t])))
#define _run_both _ufind_run(i);_ufind_run(j)
#define _set_side(x) p[abs(i)]=sig(i)*(abs(i)==abs(j)?0:(x)*j)
#define _judge_side(x) (i==(x)*j&&i)

struct ufind{
    int p[MAXN],t;
    void init(){memset(p,0,sizeof(p));}
    int set_friend(int i,int j){_run_both;_set_side(1);return !_judge_side(-1);}
    int set_enemy(int i,int j){_run_both;_set_side(-1);return !_judge_side(1);}
    int is_friend(int i,int j){_run_both;return _judge_side(1);}
    int is_enemy(int i,int j){_run_both;return _judge_side(-1);}
};
