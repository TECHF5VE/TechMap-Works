import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Task_03_Tree {
    public static void main(String[] args) {
        System.out.println("这是01，02，04");
        String s="ABD  E  CF   ";
//        String s="ABDG   E HCFI  J     ";
        System.out.println("当前字符串为:"+s);
        Tree tree = new Tree(s);
        if (tree.createTreePreOrder()){
            System.out.print("前序遍历");
            tree.preOrder();
            System.out.print("中序遍历");
            tree.midOrder();
            System.out.print("后序遍历");
            tree.postOrder();
            System.out.print("层序遍历");
            tree.floorOrder();
        }else {
            System.out.println("创建失败");
        }
        tree.deleteNode('C');
        System.out.print("中序遍历");
        tree.midOrder();
        System.out.println("===========================");
        System.out.println("这是03");
        String s1="421  3  65   ";
        String s2="20  8  ";
        binarySortTree binarySortTree = new binarySortTree();
        TreeNode treeNode1 = new TreeNode(s1);
        TreeNode treeNode2 = new TreeNode(s2);
        System.out.println("1号:");
        binarySortTree.midOrder(treeNode1);
        System.out.println("\n2号:");
        binarySortTree.midOrder(treeNode2);
        System.out.println("\n合体:");
        List<Character> characters = binarySortTree.allOrderSort(treeNode1, treeNode2);
        for (Character character : characters) {
            System.out.print(character+" ");
        }
    }
}
/*
这是Task_03第1，2，4个任务用到的类
 */
class Tree {
    private Node root;
    private final String s;

    public Tree(String s) {
        this.s = s;
        this.root = new Node(s.charAt(0));
    }

    public void preOrder() {
        if (root != null) {
            root.preOrder();
            System.out.println();
        } else {
            System.out.println("空");
        }
    }

    public void midOrder() {
        if (root != null) {
            root.midOrder();
            System.out.println();
        } else {
            System.out.println("空");
        }
    }

    public void postOrder() {
        if (root != null) {
            root.postOrder();
            System.out.println();
        } else {
            System.out.println("空");
        }
    }

    public void floorOrder() {
        if (root != null) {
            System.out.print(root);
            root.floorOrder();
            System.out.println();
        } else {
            System.out.println("空");
        }

    }

    public boolean createTreePreOrder() {
        if (root == null) {
            return false;
        } else {
            root.createTreePreOrder(this.s);
            return true;
        }
    }

    public void deleteNode(char a){
        if (root.character==a){
            Node leftNode= root.leftNode;
            if (root.rightNode!=null){
                Node node=root.getNextNode();
                if (node==root.rightNode){
                    root=node;
                    root.leftNode=leftNode;
                }else {
                    Node rightNode=root.rightNode;
                    root=node;
                    root.rightNode=rightNode;
                    root.leftNode=leftNode;
                }
            }else {
                root=root.getNextNode();
            }
        }else {
            root.deleteNode(a);
        }
    }
}

class Node{
    char character;
    Node leftNode;
    Node rightNode;
    static int index=1;
    static int select=0;

    public void createTreePreOrder(String s){
        if (index>s.length()){
            return;
        }
        char temp=s.charAt(index++);
        if (temp!=' '){
            this.leftNode=new Node(temp);
            this.leftNode.createTreePreOrder(s);
        }
        if (index>s.length()){
            return;
        }
        temp=s.charAt(index++);
        if (temp!=' '){
            this.rightNode=new Node(temp);
            this.rightNode.createTreePreOrder(s);
        }
    }

    public void preOrder(){
        System.out.print(this);
        if (this.leftNode!=null){
            this.leftNode.preOrder();
        }
        if (this.rightNode!=null){
            this.rightNode.preOrder();
        }
    }

    public void midOrder(){
        if (this.leftNode!=null){
            this.leftNode.midOrder();
        }
        System.out.print(this);
        if (this.rightNode!=null){
            this.rightNode.midOrder();
        }
    }

    public void postOrder(){
        if (this.leftNode!=null){
            this.leftNode.midOrder();
        }
        if (this.rightNode!=null){
            this.rightNode.midOrder();
        }
        System.out.print(this);
    }

    public void floorOrder(){
        if (this.leftNode!=null){
            System.out.print(this.leftNode);
        }
        if (this.rightNode!=null){
            System.out.print(this.rightNode);
        }
        if (this.leftNode!=null&&select==0){
            this.leftNode.floorOrder();
            select=1;
        }if (this.rightNode!=null&&select==1){
            this.rightNode.floorOrder();
            select=0;
        }
    }

    public Node(char character) {
        this.character = character;
    }

    @Override
    public String toString() {
        return character+"";
    }

    /**
     *
     * @return 最左边的Node
     *          并切断与父节点的联系
     */
    public Node getLeftmostNode(){
        if (this.leftNode==null){
            return this;
        }else {
            if (this.leftNode.leftNode==null){
                Node leftNode=this.leftNode;
                this.leftNode=null;
                return leftNode;
            }else {
                return leftNode.getLeftmostNode();
            }
        }
    }

    /**
     *
     * @return 最右边的Node
     *         并切断与父节点的联系
     */
    public Node getRightmostNode(){
        if (this.rightNode==null){
            return this;
        }else {
            if (this.rightNode.rightNode==null){
                Node leftNode=this.rightNode;
                this.rightNode=null;
                return leftNode;
            }else {
                return rightNode.getLeftmostNode();
            }
        }
    }

    public Node getNextNode(){
        /*
        如果没右边，就返回左边一个的最右边
        如果都没有，就返回空，让delete函数来切断
        否则，就返回右边一个的最左边
         */
        if (this.rightNode==null){
            if (this.leftNode!=null){
                return this.leftNode.getRightmostNode();
            }else {
                return null;
            }
        }else{
            return this.rightNode.getLeftmostNode();
        }
    }

    public void deleteNode(char a){
        /*
        getNextNode()若返回的为null，则就是该节点
                     若返回的为
        如果没右边，就返回左边一个的最右边
        如果都没有，就返回空，让delete函数来切断
        否则，就返回右边一个的最左边
         */
        if (this.leftNode!=null){
            if (this.leftNode.character==a){
                if (this.leftNode.rightNode==null){
                    //左边一个的最右边
                    Node rightmostNode=this.leftNode.getNextNode();
                    /*
                    1.null  说明this.leftNode无子节点
                    2.this.leftNode.left
                    3.与this.leftNode无直接关系
                     */
                    if (rightmostNode==null){
                        this.leftNode=null;
                    }else if (rightmostNode==this.leftNode.leftNode){
                        this.leftNode=this.leftNode.leftNode;
                    }else {
                        Node node=this.leftNode.leftNode;
                        this.leftNode=rightmostNode;
                        rightmostNode.leftNode=node;
                    }
                }else {
                    //有俩子节点
                    //找右边一个的最左边
                    Node leftmostNode=this.leftNode.getNextNode();
                    /*
                    1.this.leftNode.right
                    2.与this.leftNode无直接关系
                     */
                    if (leftmostNode==this.leftNode.rightNode){
                        Node node=this.leftNode.leftNode;
                        this.leftNode=leftmostNode;
                        leftmostNode.leftNode=node;
                    }else {
                        Node right=this.leftNode.rightNode;
                        Node left=this.leftNode.leftNode;
                        this.leftNode=leftmostNode;
                        leftmostNode.rightNode=right;
                        leftmostNode.leftNode=left;
                    }
                }return;
            }else {
                this.leftNode.deleteNode(a);
            }
        }if (this.rightNode!=null){
            if (this.rightNode.character==a){
                if (this.rightNode.rightNode==null){
                    Node rightmostNode=this.rightNode.getNextNode();
                    if (rightmostNode==null){
                        this.rightNode=null;
                    }else if (rightmostNode==this.rightNode.leftNode){
                        this.rightNode=this.rightNode.leftNode;
                    }else {
                        Node node=this.rightNode.leftNode;
                        this.rightNode=rightmostNode;
                        rightmostNode.leftNode=node;
                    }
                }else {
                    Node leftmostNode=this.rightNode.getNextNode();
                    if (leftmostNode==this.rightNode.rightNode){
                        Node node=this.rightNode.leftNode;
                        this.rightNode=leftmostNode;
                        leftmostNode.leftNode=node;
                    }else {
                        Node right=this.rightNode.rightNode;
                        Node left=this.rightNode.leftNode;
                        this.rightNode=leftmostNode;
                        leftmostNode.rightNode=right;
                        leftmostNode.leftNode=left;
                    }
                }
            }else {
                this.rightNode.deleteNode(a);
            }
        }
    }
}
/*
这是Task_03中第4个任务中用到的类
 */
class TreeNode {
    Character x;
    TreeNode leftNode;
    TreeNode rightNode;
    public TreeNode(Character x) {
        this.x = x;
    }

    public TreeNode(String s){
        this.x=s.charAt(0);
        for (int i=1;i<s.length();i++){
            this.add(new TreeNode(s.charAt(i)));
        }
    }

    public void add(TreeNode node){
        if (node==null||node.x==' '){
            return;
        }
        if (node.x<this.x){
            if (this.leftNode==null){
                this.leftNode=node;
            }else {
                this.leftNode.add(node);
            }
        }else {
            if (this.rightNode==null){
                this.rightNode=node;
            }else {
                this.rightNode.add(node);
            }
        }
    }
}

class binarySortTree {
    public List<Character> allOrderSort(TreeNode root1, TreeNode root2){
        List<Character> list1=new ArrayList<>();
        List<Character> list2=new ArrayList<>();
        Stack<TreeNode> stack1=new Stack<>();
        Stack<TreeNode> stack2=new Stack<>();
        while (root1!=null||!stack1.isEmpty()){
            if (root1!=null){
                stack1.push(root1);
                root1=root1.leftNode;
            }else {
                root1=stack1.pop();
                //此时已将最左边的压入
                list1.add(root1.x);
                root1=root1.rightNode;
            }
        }
        while (root2!=null||!stack2.isEmpty()){
            if (root2!=null){
                stack2.push(root2);
                root2=root2.leftNode;
            }else {
                root2=stack2.pop();
                //此时已将最左边的压入
                list2.add(root2.x);
                root2=root2.rightNode;
            }
        }
        List<Character> result=new ArrayList<>();
        int lis1Size=list1.size();
        int list2Size=list2.size();
        for (int i=0,j=0;;){
            if (list1.get(i)<list2.get(j)){
                result.add(list1.get(i++));
            }else {
                result.add(list2.get(j++));
            }
            if (i==lis1Size){
                result.addAll(list2.subList(j,list2Size));
                break;
            }
            if (j==list2Size){
                result.addAll(list1.subList(i,lis1Size));
                break;
            }
        }
        return result;
    }

    public void midOrder(TreeNode root){
        Stack<TreeNode> stack=new Stack<>();
        while (root!=null||!stack.isEmpty()){
            if (root!=null){
                stack.push(root);
                root=root.leftNode;
            }else {
                root=stack.pop();
                System.out.print(root.x+" ");
                root=root.rightNode;
            }
        }
    }
}