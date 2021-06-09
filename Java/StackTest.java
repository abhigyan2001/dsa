import java.util.Scanner;
class StackTest{
    public static void main(String args[]){
        System.out.println("Bracket Matching Algorithm\n_________________");
        Scanner sn = new Scanner(System.in);
        boolean stopper = true;
        char choice;
        do{
            System.out.println("Enter a Pattern of Brackets: ");
            String bracks = sn.nextLine();
            System.out.println(BracketsMatch(bracks));
            System.out.println("Would you like to try again? (y/n)");
            choice = (char) sn.nextLine().charAt(0);
            if (choice=='n'){
                stopper = false;
            }
            else if(choice!='y'){
                System.out.println("Please enter only y or n (restarting...)\n");
                continue;
            }
        }while(stopper == true);
        sn.close();
    }
    private static boolean BracketsMatch(String bracks){
        Stack<Character> stack = new Stack<Character>(bracks.charAt(0));
        for (int i = 1; i < bracks.length(); i++){
            char brack = bracks.charAt(i);
            if (BrackFwd(brack)){
                stack.push(brack);
            }
            else {
                if (RevBrack(brack) == stack.peek()){
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (stack.isEmpty()){
            return true;
        }
        return false;
    }
    private static boolean BrackFwd(char brack){
        switch (brack){
            case '{':
            case '[':
            case '(':
            case '<':
                return true;
            case '}':
            case ']':
            case ')':
            case '>':
                return false;
            default:
                System.err.println("Only Brackets are allowed");
                System.exit(0);
                return false;
        }
    }
    private static char RevBrack(char brack){
        switch(brack){
            case '}':
                return '{';
            case ']':
                return '[';
            case ')':
                return '(';
            case '>':
                return '<';
            default:
                System.err.println("Only Brackets are allowed");
                System.exit(0);
                return (char)0;
        }
    }
}