// a visitor can traverse the tree but can't change it

import java.util.ArrayList;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.util.ArrayList;
import java.util.Scanner;

enum Color {
    RED, GREEN
}

abstract class Tree {

    private int value;
    private Color color;
    private int depth;

    public Tree(int value, Color color, int depth) {
        this.value = value;
        this.color = color;
        this.depth = depth;
    }

    public int getValue() {
        return value;
    }

    public Color getColor() {
        return color;
    }

    public int getDepth() {
        return depth;
    }

    public abstract void accept(TreeVis visitor);
}

class TreeNode extends Tree {

    private ArrayList<Tree> children = new ArrayList<>();

    public TreeNode(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitNode(this);

        for (Tree child : children) {
            child.accept(visitor);
        }
    }

    public void addChild(Tree child) {
        children.add(child);
    }
}

class TreeLeaf extends Tree {

    public TreeLeaf(int value, Color color, int depth) {
        super(value, color, depth);
    }

    public void accept(TreeVis visitor) {
        visitor.visitLeaf(this);
    }
}

abstract class TreeVis
{
    public abstract int getResult();
    public abstract void visitNode(TreeNode node);
    public abstract void visitLeaf(TreeLeaf leaf);

}

///////////////////////////////////////////
// MY CODE END

class SumInLeavesVisitor extends TreeVis {
    int result = 0;
    public int getResult() {
        return result;
    }

    public void visitNode(TreeNode node) {
    }

    public void visitLeaf(TreeLeaf leaf) {
      	this.result += leaf.getValue();
    }
}

class ProductOfRedNodesVisitor extends TreeVis {
    long result = 1;
    public int getResult() {
        return (int)result;
    }
    
    private void visitEither(Tree tree)
    {
        if(tree.getColor()==Color.RED)
        {
            result *= tree.getValue();
            result %= 1000000007;
        }
    }
    

    public void visitNode(TreeNode node) {
      	visitEither(node);
    }

    public void visitLeaf(TreeLeaf leaf) {
      	visitEither(leaf);
    }
}

class FancyVisitor extends TreeVis {
    int result = 0;
    public int getResult() {
        return Math.abs(result);
    }

    public void visitNode(TreeNode node) {
        if(node.getDepth()%2==0)
            result += node.getValue();
    }

    public void visitLeaf(TreeLeaf leaf) {
        if(leaf.getColor()==Color.GREEN)
            result -= leaf.getValue();
    }
}

public class Solution {
  
    public static Tree solve() {
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        
        //build my own tree with editable nodes
        class myNode {
            Color color;
            int depth = 0;
            int value;
            boolean leaf = true;
            int index;
            ArrayList<myNode> neighbors = new ArrayList<>();
            myNode(int index)
            {
                this.index = index;
            }
        }
        
        //array of nodes for converting edges to neighbors 
        myNode[] myNodes = new myNode[n];
        for(int i = 0; i < n; i++)
            myNodes[i] = new myNode(i);
        
        //input values
        for(int i = 0; i < n; i++)
            myNodes[i].value = scan.nextInt();
        
        //input colors    
        for(int i = 0; i < n; i++)
            myNodes[i].color = scan.nextInt()==0?Color.RED:Color.GREEN;
        
        //edges -> neighbors (may be parent child or child parent)
        for(int i = 0; i < n-1; i++)
        {
            int n1 = scan.nextInt()-1;
            int n2 = scan.nextInt()-1;
            myNodes[n1].neighbors.add(myNodes[n2]);
            myNodes[n2].neighbors.add(myNodes[n1]);
        }
        
        //root has depth 0
        myNodes[0].depth = 0;
        //go through nodes adding depth, non-recursive way
        Queue<myNode> toProcess = new LinkedList<>();
        toProcess.add(myNodes[0]);
        while(!toProcess.isEmpty())
        {
            myNode current = toProcess.remove();
            if(!current.neighbors.isEmpty())
                current.leaf = false;
            for(myNode child : current.neighbors)
            {
                child.depth = current.depth+1;
                toProcess.add(child);
                //remove child's parent neighbor so neighbors is actually children
                child.neighbors.remove(current);
            }
        }
        
        //create the actual nodes
        Tree[] actuals = new Tree[n];
        for(int i = 0; i < n; i++)
        {
            myNode current = myNodes[i];
            if(myNodes[i].leaf)
                actuals[i] = new TreeLeaf(current.value, current.color, current.depth);
            else
                actuals[i] = new TreeNode(current.value, current.color, current.depth);
        }
        
        //set up children for actual nodes
        for(int i = 0; i < n; i++)
        {
            myNode current = myNodes[i];
            if(current.leaf)
                continue;
            //else
            TreeNode current_actual = (TreeNode) actuals[i];
            for(myNode child : current.neighbors)
            {
                current_actual.addChild(actuals[child.index]);
            }
        }
        
        return actuals[0];
    }

// MY CODE END
///////////////////////////////////////////

    public static void main(String[] args) {
      	Tree root = solve();
		SumInLeavesVisitor vis1 = new SumInLeavesVisitor();
      	ProductOfRedNodesVisitor vis2 = new ProductOfRedNodesVisitor();
      	FancyVisitor vis3 = new FancyVisitor();

      	root.accept(vis1);
      	root.accept(vis2);
      	root.accept(vis3);

      	int res1 = vis1.getResult();
      	int res2 = vis2.getResult();
      	int res3 = vis3.getResult();

      	System.out.println(res1);
     	System.out.println(res2);
    	System.out.println(res3);
	}
}