package com.xizhe;

import java.util.*;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 11:13
 */

public class Solution {


    /**
     * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
     *
     * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if( n == 0) {
            return;
        }

//        if( m == 0) {
//            nums1 = nums2.clone();
//            return;
//        }

        int i = m;
        int j = 0;
        while(i < m+n) {
            nums1[i++] = nums2[j++];
        }
        Arrays.sort(nums1);
    }


    /**
     * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
     *
     * 有效字符串需满足：
     *
     *     左括号必须用相同类型的右括号闭合。
     *     左括号必须以正确的顺序闭合。
     *     每个右括号都有一个对应的相同类型的左括号。
     */

    public boolean isValid(String s) {
        if((s.length() % 2) == 1) {
            return false;
        }
        Stack<Character> stack = new Stack<>();
        for( int i=0;i<s.length(); i++) {
            char c = s.charAt(i);
            if('(' == c || '{'==c  || '['== c) {
                stack.push(c);
            }else {
                if(stack.empty()) {
                    return false;
                }
                Character pop = stack.pop();
                if(pop == '(' && c != ')' || pop == '{' && c != '}' || pop == '[' && c != ']') {
                    return false;
                }
            }
        }
        return stack.empty();
    }


}
