public class RandomizedSet {

    /** Initialize your data structure here. */
    public RandomizedSet() {
        list = new ArrayList<>();
        map = new HashMap<>();
        random = new Random();
        size = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(map.containsKey(val)) {
            return false;
        }
        if(list.size() == size) {
            list.add(val);
        } else {
            list.set(size, val);
        }
        map.put(val, size);
        ++size;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!map.containsKey(val)) {
            return false;
        }
        int index = map.get(val);
        // swap this one with the last one
        --size;
        int t = list.get(size);
        list.set(size, list.get(index));
        list.set(index, t);

        map.put(list.get(size), size);
        map.put(list.get(index), index);
        map.remove(list.get(size));
        return true;
    }

    /** Get a random element from the set. */
    public int getRandom() {
        return list.get(random.nextInt(size));
    }

    private ArrayList<Integer> list;
    private HashMap<Integer, Integer> map;
    private Random random;
    private int size;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
