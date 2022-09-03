
/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function (root) {
    const queue = new Queue();
    queue.enqueue(root);

    const averageForEachLevel = [];
    averageForEachLevel.push(root.val);

    while (!queue.isEmpty()) {
        let sumCurrentLevel = 0;

        for (let i = queue.size(); i > 0; --i) {

            const current = queue.dequeue();

            if (current.left !== null) {
                sumCurrentLevel += current.left.val;
                queue.enqueue(current.left);
            }
            if (current.right !== null) {
                sumCurrentLevel += current.right.val;
                queue.enqueue(current.right);
            }
        }

        if (queue.size() > 0) {
            averageForEachLevel.push(sumCurrentLevel / queue.size());
        }
    }
    return averageForEachLevel;
};
