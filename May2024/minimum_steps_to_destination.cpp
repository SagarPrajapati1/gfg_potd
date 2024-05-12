class Solution {
  public:
    int minSteps(int d) {
        int add = 1;
        int element = 0, count = 0;
        while(element<d){
            element+=add;
            add++;
            count++;
        }
        
        while((element-d)%2 != 0){
            count++;
            element+=add;
            add++;
        }
        return count;
    }
};
