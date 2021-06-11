package com.aacirq.string;

public class N44 {
    public static void main(String[] args) {
        N44 sol = new N44();

        // "I am a nowcoder."
        System.out.println("\"" + sol.ReverseSentence("nowcoder. a am I") + "\"");
        // ""
        System.out.println("\"" + sol.ReverseSentence("") + "\"");
        // " "
        System.out.println("\"" + sol.ReverseSentence(" ") + "\"");
        // "  "
        System.out.println("\"" + sol.ReverseSentence("  ") + "\"");
    }

    public String ReverseSentence(String str) {
        if (str.length() == 0)
            return str;
        StringBuilder res = new StringBuilder();
        int sInd = str.length() - 1;
        int eInd = sInd;
        while (sInd >= 0) {
            while (sInd >= 0 && str.charAt(sInd) != ' ')
                sInd--;
            res.append(str.substring(sInd + 1, eInd + 1));
            if (sInd >= 0)
                res.append(' ');
            eInd = sInd - 1;
            sInd = eInd;
        }
        return res.toString();
    }
}
