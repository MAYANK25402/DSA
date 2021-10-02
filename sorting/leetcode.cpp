class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector <int> arr;
        map<int,int> mp;
        // map <int,int> mp1;
        for (int i =0;i<n1;i++){
            mp[nums1[i]]++;
        }
        // for (int i =0;i<n2;i++){
        //     mp1[nums2[i]]++;
        // }
        sort(nums2.begin(),nums2.end());
        for (int i =0;i<n2;i++){
            
           // mp[nums1[i]] -> frequancy
          //  nums[i]  -> map first
            if(mp[nums2[i]] > 0){
                arr.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
          
        }

//         for(auto x : mp){
//             for(auto y : mp1){
             
//                  if(x.first==y.first ){
//                      // cout<<x.second<<" ";
//                      while(x.second!=0 and y.second!=0){
//                             arr.push_back(x.first);
//                             x.second--;
//                             y.second--;
//                             // mp[x.second]--;
//                          // mp1[y.second]--;
//                      }
                            
//                 }
//             }
//         }
        
       
    return arr;
    }
};
