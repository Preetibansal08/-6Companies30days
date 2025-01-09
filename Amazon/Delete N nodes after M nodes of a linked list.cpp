/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node *cur = head;
        Node *nxt = head->next;
        int N, M;
        
        while(cur != NULL && cur->next != NULL) {
            M = m; N = n;
            while (M > 1) {
                if(cur != NULL && nxt != NULL) {
                    cur = cur->next;
                    nxt = nxt->next;
                }
                M--;
            }
            while (N > 1) {
                if(nxt != NULL)
                    nxt = nxt->next;
                N--;
            }
            
            if(nxt == NULL) {
                cur->next = NULL;
                cur = cur->next;
            }
            if(cur != NULL && nxt != NULL) {
                cur->next = nxt->next;
                cur = cur->next;
            }
            if(cur != NULL)
                nxt = cur->next;
        }
        return head;
    }
};
