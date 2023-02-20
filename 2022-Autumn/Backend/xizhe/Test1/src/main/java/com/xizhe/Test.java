package com.xizhe;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 11:11
 */

public class Test {

    public static void main(String[] args) {
        Solution solution = new Solution();
        int nums1[] = new int[]{0};
        int nums2[] = new int[]{1};
        solution.merge(nums1,0,nums2,1);

        solution.isValid("([)]");
    }
}
