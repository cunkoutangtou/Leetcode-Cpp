运用所掌握的数据结构，设计和实现一个  LRU (Least Recently Used，最近最少使用) 缓存机制 。

实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put
 

进阶：是否可以在 O(1) 时间复杂度内完成这两种操作？

 

注意：本题与主站 146 题相同：https://leetcode-cn.com/problems/lru-cache/ 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/OrIXps

//使用双向链表，链表前端表示最久未用，链表后端表示最近被用。用hash表存储每个key对应的节点地址，实现随机访问。
struct node{
    node*prev=nullptr,*next=nullptr;
    int num;
    int data;
    node(int num,int data):num(num),data(data){}
};
class LRUCache {
    map<int,node*> m;
    int capacity;
    node *tail,*head;//尾结点用于将最近使用节点插入，头结点用于删除最久未用节点。
    int cur=0;
    void move2tail(node *p){
        if(p==tail)
        return;
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->next=tail->next;
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
public:
    LRUCache(int capacity):capacity(capacity) {
        head=new node(0,0);
        tail=head;
    }
    
    int get(int key) {
        if(!m.count(key))
        return -1;
        node *p=m[key];
        move2tail(p);
        return p->data;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            node *p=m[key];
            move2tail(p);
            p->data=value;
        }else{
            if(cur<capacity){
                node *p=new node(key,value);
                m[key]=p;
                p->next=tail->next;
                tail->next=p;
                p->prev=tail;
                tail=p;
                cur++;
            }else{
                node *p=head->next;
                m[key]=p;
                m.erase(p->num);
                head->next=p->next;
                if(p->next)
                p->next->prev=head;
                p->num=key;
                p->data=value;
                p->next=tail->next;
                tail->next=p;
                p->prev=tail;
                tail=p;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
