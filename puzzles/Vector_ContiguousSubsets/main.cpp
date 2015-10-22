vector<vector<int>> subsets_num(vector<int>& nums) {
    
    vector<vector<int>> result;
    //sort(nums.begin(), nums.end());
    
    result.push_back(vector<int>{});
    
    for(int len = 1; len<=nums.size(); len++){
        for(int i=0; i<nums.size() - len + 1; i++){
            vector<int>::iterator first = nums.begin() + i;
            vector<int>::iterator second = nums.begin() + i + len;
            result.push_back(vector<int>(first, second));
        }
    }
    
    return result;
}