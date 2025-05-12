#include<stdio.h>
#define max 1000

int tree[max];

void build(int a[],int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(a,2*node,start,mid);
    build(a,2*node+1,mid+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int end,int l,int r)
{
    if(r<start||l>end)
        return 0;
    if(l<=start&&end<=r)
        return tree[node];
    int mid=(start+end)/2;
    return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    if(idx<=mid)
        update(2*node,start,mid,idx,val);
    else
        update(2*node+1,mid+1,end,idx,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void main()
{
    int a[]={1,3,5,7,9,11};
    int n=sizeof(a)/sizeof(a[0]);
    build(a,1,0,n-1);
    printf("\nsum[1,3] = %d",query(1,0,n-1,1,3));
    update(1,0,n-1,2,10);
    printf("\nafter update sum[1,3] = %d",query(1,0,n-1,1,3));
}