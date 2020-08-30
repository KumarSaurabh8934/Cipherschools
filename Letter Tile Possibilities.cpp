class Solution {
private:
    set<string> all;
    void subset(string tiles, int i, string temp) {
        if (i == tiles.size()) {
            all.insert(temp);
            while (next_permutation(temp.begin(), temp.end()))
                all.insert(temp);
            return;
        }
        temp += tiles[i];
        subset(tiles, i+1, temp);
        temp.pop_back();
        subset(tiles, i+1, temp);
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        subset(tiles, 0, "");
        return all.size()-1;
    }
};
