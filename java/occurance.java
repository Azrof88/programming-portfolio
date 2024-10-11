import java.util.AbstractMap.SimpleEntry;
import java.util.Scanner;
import java.util.Vector;

public class occurance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = scanner.nextInt();
        int[] arr;
        arr = new int[n];
        // scanner.close();

        Vector<SimpleEntry<Integer, Integer>> vector = new Vector<>(0, 0);
        System.out.println("Enter the value of array:");

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
            // vector.add(new SimpleEntry<Integer, Integer>(arr[i], vector.get(i).getValue()
            // + 1));

        }
        for (int num : arr) {
            boolean found = false;
            // per time for new value this loop will not enter
            for (int j = 0; j < vector.size(); j++) {
                if (vector.get(j).getKey().equals(num)) {
                    // Increment the count
                    SimpleEntry<Integer, Integer> entry = vector.get(j);
                    vector.set(j, new SimpleEntry<>(entry.getKey(), entry.getValue() + 1));
                    found = true;
                    break;
                }
            }
            if (!found) {
                // Add new entry if not found
                vector.add(new SimpleEntry<>(num, 1));
            }
        }
        System.out.println("Enter the finding value occurrance:");
        int find = scanner.nextInt();

        for (int i = 0; i < vector.size(); i++) {
            if (find == vector.get(i).getKey()) {
                System.out.println(vector.get(i).getValue());
                break;
            }
        }
        scanner.close();

    }

}
