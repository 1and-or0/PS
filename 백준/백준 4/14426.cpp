#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Ʈ���� ��带 �����ϴ� Ŭ����
class TrieNode
{
public:
    unordered_map<char, TrieNode*> children; // �ڽ� ��带 �����ϴ� ��
    bool isEndOfWord; // �ܾ��� ���� ǥ���ϴ� �÷���

    // ������: isEndOfWord�� false�� �ʱ�ȭ
    TrieNode() : isEndOfWord(false) {}
};

// Ʈ���� ������ �����ϴ� Ŭ����
class Trie
{
private:
    TrieNode* root; // ��Ʈ ��带 ����Ŵ

    // ��� ��带 �����ϴ� ��� �Լ�
    void deleteNodes(TrieNode* node)
    {
        for (auto& child : node->children)
        {
            deleteNodes(child.second); // �ڽ� ��带 ��������� ����
        }
        delete node; // ���� ��� ����
    }

public:
    // ������: ��Ʈ ��带 �ʱ�ȭ
    Trie()
    {
        root = new TrieNode();
    }

    // �Ҹ���: ��� ��带 �����Ͽ� �޸� ����
    ~Trie()
    {
        deleteNodes(root); // ��Ʈ ������ ��� ��� ����
    }

    // ���ڿ��� Ʈ���̿� �����ϴ� �Լ�
    void insert(const string& word)
    {
        TrieNode* node = root;
        for (char ch : word) // �ܾ��� �� ���ڸ� ��ȸ
        {
            // ���ڰ� �ڽ� ��忡 ���ٸ� ���� �߰�
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            // ���� ���� �̵�
            node = node->children[ch];
        }
        // �ܾ��� ���� ���������� ǥ��
        node->isEndOfWord = true;
    }

    // ���ڿ��� Ʈ���̿� �ִ� �ܾ��� ���λ����� Ȯ���ϴ� �Լ�
    bool startsWith(const string& prefix)
    {
        TrieNode* node = root;
        for (char ch : prefix) // ���λ��� �� ���ڸ� ��ȸ
        {
            // ���ڰ� �ڽ� ��忡 ������ ���λ� �ƴ�
            if (node->children.find(ch) == node->children.end())
            {
                return false;
            }
            // ���� ���� �̵�
            node = node->children[ch];
        }
        return true; // ��� ���� ��ȸ �� ���λ� Ȯ�� �Ϸ�
    }
};

int main()
{
    ios::sync_with_stdio(false); // C ǥ�� ����°��� ����ȭ ��Ȱ��ȭ
    cin.tie(nullptr); // cin�� cout�� ������ �����Ͽ� ����� ���� ���

    int N, M;
    cin >> N >> M;
    Trie trie;
    string word;

    // S ������ �ܾ���� Ʈ���̿� ����
    for (int i = 0; i < N; ++i)
    {
        cin >> word;
        trie.insert(word);
    }

    int count = 0;

    // P ������ �� �ܾ ���λ�� �����ϴ��� Ȯ��
    for (int i = 0; i < M; ++i)
    {
        cin >> word;
        if (trie.startsWith(word))
        {
            ++count;
        }
    }

    // ���λ�� �����ϴ� �ܾ��� ���� ���
    cout << count << '\n';

    return 0;
}
