class Solution {

    void dfs(String word,String begin,Map<String,List<String>> par,List<String> curr,List<List<String>> ans){
        if(word.equals(begin)){
            List<String> temp=new ArrayList<>(curr);
            Collections.reverse(temp);
            ans.add(temp);
            return;
        }
        for(String p:par.get(word)){
            curr.add(p);
            dfs(p,begin,par,curr,ans);
            curr.remove(curr.size()-1);
        }
    }

    public List<List<String>> findLadders(String beginWord,String endWord,List<String> wordList){

        Set<String> set=new HashSet<>(wordList);
        if(!set.contains(endWord))return new ArrayList<>();

        Map<String,List<String>> par=new HashMap<>();
        for(String w:wordList)par.put(w,new ArrayList<>());
        par.put(beginWord,new ArrayList<>());
        par.put(endWord,new ArrayList<>());

        Queue<String> q=new LinkedList<>();
        q.offer(beginWord);

        Set<String> vis=new HashSet<>();
        vis.add(beginWord);

        boolean found=false;
        Set<String> localVis=new HashSet<>();

        while(!q.isEmpty() && !found){
            int sz=q.size();
            localVis.clear();

            for(int i=0;i<sz;i++){
                String cur=q.poll();
                char[] arr=cur.toCharArray();

                for(int j=0;j<arr.length;j++){
                    char orig=arr[j];

                    for(char c='a';c<='z';c++){
                        if(c==orig)continue;
                        arr[j]=c;
                        String nxt=new String(arr);

                        if(set.contains(nxt) && !vis.contains(nxt)){
                            if(nxt.equals(endWord))found=true;
                            if(!localVis.contains(nxt)){
                                q.offer(nxt);
                                localVis.add(nxt);
                            }
                            par.get(nxt).add(cur);
                        }
                    }
                    arr[j]=orig;
                }
            }

            vis.addAll(localVis);
        }

        List<List<String>> ans=new ArrayList<>();
        if(!found)return ans;

        List<String> curr=new ArrayList<>();
        curr.add(endWord);
        dfs(endWord,beginWord,par,curr,ans);

        return ans;
    }
}