
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public List<Double> averageOfLevels(TreeNode root) {

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        List<Double> averageForEachLevel = new ArrayList<>();
        averageForEachLevel.add((double) root.val);

        while (!queue.isEmpty()) {
            double sumCurrentLevel = 0;

            for (int i = queue.size(); i > 0; --i) {

                TreeNode current = queue.poll();

                if (current.left != null) {
                    sumCurrentLevel += current.left.val;
                    queue.add(current.left);
                }
                if (current.right != null) {
                    sumCurrentLevel += current.right.val;
                    queue.add(current.right);
                }
            }

            if (queue.size() > 0) {
                averageForEachLevel.add(sumCurrentLevel / queue.size());
            }
        }
        return averageForEachLevel;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
