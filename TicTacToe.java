package SwaraliPractice;
import java.io.*;
import java.util.*;
public class TicTacToe {
    static HashSet<Integer> ur_set= new HashSet<Integer>(); // You
    static HashSet<Integer> comp_set= new HashSet<Integer>(); // Computer

    public static void main(String[] args) {
        char[][] g_boards={
                {' ','|',' ','|',' '},
                {'-','|','-','|','-'},
                {' ','|',' ','|',' '},
                {'-','|','-','|','-'},
                {' ','|',' ','|',' '}
        };
        print_boards(g_boards);

        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.print("Enter values from 1-9: ");
            int user_pos=sc.nextInt();
            while(ur_set.contains(user_pos) || comp_set.contains(user_pos)){ // to check repeated position
                System.out.println();
                System.out.print("Occupied position. Retry, Enter numbers from 1-9:");
                user_pos=sc.nextInt();
             }
          p_holder(g_boards,user_pos,"You");
          String res=check_winner();
            if(res.length()>0){
                System.out.println(res);
                break;
            }

            int cpu_pos=gen_random();
            while(ur_set.contains(cpu_pos) || comp_set.contains(cpu_pos)){  // to check repeated position
                cpu_pos=gen_random();
            }
            p_holder(g_boards,cpu_pos,"Comp");
            res=check_winner();
            if(res.length()>0){
                System.out.println(res);
                break;
            }

        }

    }

    static String check_winner()
    {
        HashSet<Integer> r1=new HashSet<Integer>();
        r1.add(1);r1.add(2);r1.add(3);
        HashSet<Integer> r2=new HashSet<Integer>();
        r2.add(4);r2.add(5);r2.add(6);
        HashSet<Integer> r3=new HashSet<Integer>();
        r3.add(7); r3.add(8);r3.add(9);
        HashSet<Integer> c1=new HashSet<Integer>();
        c1.add(1);c1.add(4);c1.add(7);
        HashSet<Integer> c2=new HashSet<Integer>();
        c2.add(2);c2.add(5);c2.add(8);
        HashSet<Integer> c3=new HashSet<Integer>();
        c3.add(3);c3.add(6);c3.add(9);
        HashSet<Integer> d1=new HashSet<Integer>();
        d1.add(1);d1.add(5);d1.add(9);
        HashSet<Integer> d2=new HashSet<Integer>();
        d2.add(3); d2.add(5);d2.add(7);

        HashSet<HashSet> check = new HashSet<HashSet>();
        check.add(r1);check.add(r2);check.add(r3);
        check.add(c1);check.add(c2);check.add(c3);
        check.add(d1); check.add(d2);


        for(HashSet l : check)  {
            if(ur_set.containsAll(l))
                return "YOU WON";
            else if (comp_set.containsAll(l))
                return "YOU LOSE";

        }
        if (ur_set.size()+comp_set.size()==9)
            return "ITS A DRAW";

        return "";

    }


    static int gen_random(){
        int max=9;
        int min=1;
        int range=max-min+1;

        int res=(int)(Math.random() * range) + min;  // Math.random() gives result in double. So, typecast it.
        return res;
    }

    static void print_boards(char[][] g_boards){
        for(int r=0;r<g_boards.length; r++){
            for(int c=0; c<g_boards[0].length; c++){
                System.out.print(g_boards[r][c]);
            }
            System.out.println();
        }
        System.out.println();
    }

    static void p_holder(char[][] g_board,int pos, String user){
        char syb='X';
        if(user.equals("You")) {
            syb = 'X';
            ur_set.add(pos);
        }
        else if(user.equals("Comp")) {
            syb = 'O';
            comp_set.add(pos);
        }
        switch(pos){
            case 1:
                g_board[0][0]=syb;
                break;
            case 2:
                g_board[0][2]=syb;   // there are spaces in between two elements and also between two rows
                break;
            case 3:
                g_board[0][4]=syb;
                break;
            case 4:
                g_board[2][0]=syb;
                break;
            case 5:
                g_board[2][2]=syb;
                break;
            case 6:
                g_board[2][4]=syb;
                break;
            case 7:
                g_board[4][0]=syb;
                break;
            case 8:
                g_board[4][2]=syb;
                break;
            case 9:
                g_board[4][4]=syb;
                break;
            default:
                System.out.println("Invalid input");

        }
        print_boards(g_board);
    }



}
