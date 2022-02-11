import java.util.ArrayList;
public class Words {
	 private ArrayList<Word2> words = new ArrayList<Word2>();
	 String word;
	 int num;
	    public Words()
	    {
	    }
	 
	    public Words(String input, int number)
	    {
	    	this.word = input;
	    	this.num = number;
	    }
	    public void setWords(String wordList, int number)
	    {
	    	for(int i = 0; i < number; i++) {
	    		word = wordList.split(" ")[i];
	    	}
	    }
	    public void addWords(Word2 wd) {
	    	words.add(wd);
	    }
	    public String getWord(int input) {
	    	return words.get(input).word;
	    }
	    public int countWordsWithXChars(int size)
	    {
	        int count=0;
	        for(int i = 0; i < words.size(); i++) {
	        	String wrd = words.get(i).word;
	        	if(wrd.length() == size) {
	        		count++;
	        	}
	        }
	        return count;
	    }
	    public int removeWordsWithXChars(int size)
	    {
	    	int count = 0;
	    	for(int i = 0; i < words.size(); i++){
	    		String wrd = words.get(i).word;
	    		if(wrd.length() == size) {
	    			for(int j = 0; j < wrd.length(); j++){
	    				String vowels = "aeiouAEIOU";
	    				for(int x = 0; x < vowels.length(); x++) {
	    					if(wrd.charAt(j) == vowels.charAt(x)) {
	    						count++;
	    					}
	    				}
	    			}
	    			words.remove(i);
	    			i--;
	    		}
	    	}
	        return count;
	    }
	 
	    public int countWordsWithXVowels(int numVowels)
	    {
	        int count=0;
	        for(int i = 0; i < words.size(); i++) {
	        	int cnt = 0;
	        	String wrd = words.get(i).word;
	        	String vowels = "aeiouAEIOU";
	        	for(int x = 0; x < wrd.length(); x++) {
	        		for(int j = 0; j < vowels.length(); j++) {
		        		if(wrd.charAt(x) == vowels.charAt(j)) {
		        			cnt++;
		        		}
		        	}
	        	}
	        	if(cnt == numVowels) {
	        		count++;
	        	}
	        }
	        return count;
	    }
	    public String mostChar() {
	    	String most = "";
	    	int mst = 0;
	    	for(int i = 0; i < words.size(); i++) {
	    		if(words.get(i).word.length() == mst) {
	    			most += " & " + words.get(i).word;
	    		}
	    		if(words.get(i).word.length() > mst) {
	    			most = words.get(i).word;
	    			mst = words.get(i).word.length();
	    		}
	    	}
	    	return most;
	    }
	    public String leastChar() {
	    	String least = "";
	    	int lst = 10;
	    	for(int i = 0; i < words.size(); i++) {
	    		if(words.get(i).word.length() == lst) {
	    			least += " & " + words.get(i).word;
	    		}
	    		if(words.get(i).word.length() < lst) {
	    			least = words.get(i).word;
	    			lst = words.get(i).word.length();
	    		}
	    	}
	    	return least;
	    }
	    public String toString()
	    {
	    	System.out.print("[");
	    	int i = 0;
	    	for(i = 0; i < words.size() - 1; i++) {
	    		System.out.print(words.get(i).word + ", ");
	    	}
	    	System.out.print(words.get(i).word + "]");
	        return "";
	    }
}
