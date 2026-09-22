class Solution {
public:
    struct Node {
        int trans[5];
        int cnt[5][5];

        Node() {
            memset(trans, 0, sizeof(trans));
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int K;
    vector<Node> seg;

    Node mergeNode(const Node &A, const Node &B) {
        Node R;

        for (int s = 0; s < K; s++) {
            R.trans[s] = B.trans[A.trans[s]];

            for (int r = 0; r < K; r++) {
                R.cnt[s][r] =
                    A.cnt[s][r] +
                    B.cnt[A.trans[s]][r];
            }
        }

        return R;
    }

    Node makeLeaf(int val) {
        Node node;

        int v = val % K;

        for (int s = 0; s < K; s++) {
            int nxt = (s * v) % K;

            node.trans[s] = nxt;
            node.cnt[s][nxt] = 1;
        }

        return node;
    }

    void build(int idx, int l, int r, vector<int> &nums) {
        if (l == r) {
            seg[idx] = makeLeaf(nums[l]);
            return;
        }

        int mid = (l + r) >> 1;

        build(idx << 1, l, mid, nums);
        build(idx << 1 | 1, mid + 1, r, nums);

        seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = makeLeaf(val);
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            update(idx << 1, l, mid, pos, val);
        else
            update(idx << 1 | 1, mid + 1, r, pos, val);

        seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(idx << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(idx << 1 | 1, mid + 1, r, ql, qr);

        Node left = query(idx << 1, l, mid, ql, qr);
        Node right = query(idx << 1 | 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        K = k;
        int n = nums.size();

        seg.assign(4 * n, Node());

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            update(1, 0, n - 1, index, value);

            Node cur = query(1, 0, n - 1, start, n - 1);

            ans.push_back(cur.cnt[1 % K][x]);
        }

        return ans;
    }
};