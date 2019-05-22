abstract class PairMap {
    protected String keyArray [];
    protected String valueArray [];
    abstract String get(String key);
    abstract void put(String key, String value);
    abstract String delete(String key);
    abstract int length();
}

class Dictionary extends PairMap {
    public Dictionary(int length){
        keyArray = new String[length];
        valueArray = new String[length];
    }
    @Override
    String get(String key) {
        for(int i=0; i<length(); i++)
        {
            if(keyArray[i].equals(key))
                return valueArray[i];
        }
        return null;
    }
    @Override
    void put(String key, String value) {
        int idx=0;
        for(idx = 0; idx < length(); idx ++) {
            if(keyArray[idx].equals(key))
                break;
        }
        keyArray[idx] = key;
        valueArray[idx] = value;
    }
    @Override
    String delete(String key){
        for(int i=0; i<length(); i++)
        {
            if(keyArray[i].equals(key)){
                String temp = valueArray[i];
                keyArray[i] = null;
                valueArray[i] = null;
                return temp;
            }
        }
        return null;
    }
    @Override
    int length(){
        int idx=0;
        while(true)
        {
            if(keyArray[idx]==null)
                return idx;
            idx ++;
        }
    }
}
public class DictionaryApp {

    public static void main(String[] args) {
        Dictionary dic = new Dictionary(10);
        dic.put("황기태", "자바");
        dic.put("이재문", "파이썬");
        dic.put("이재문", "C++");
        System.out.println("이재문의 값은 " + dic.get("이재문"));
        System.out.println("황기태의 값은 " + dic.get("황기태"));
        dic.delete("황기태");
        System.out.println("황기태의 값은 " + dic.get("황기태"));
    }
}
