package Hotel_reservation_system;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Hotel> hotelList1 = new ArrayList<>();
        List<Hotel> hotelList2 = new ArrayList<>();

        // Adding random hotels to the first collection
        hotelList1.add(new StarHotel("HTH01", "New York", "5 star", 200, "Deluxe", 10));
        hotelList1.add(new StarHotel("HTH02", "Los Angeles", "4 star", 150, "Premium", 8));
        hotelList1.add(new StarHotel("HTH03", "Chicago", "3 star", 100, "Normal", 5));
        hotelList1.add(new StarHotel("HTH04", "Miami", "5 star", 250, "Deluxe", 12));
        hotelList1.add(new StarHotel("HTH05", "San Francisco", "4 star", 180, "Premium", 6));

        // Adding random hotels to the second collection
        hotelList2.add(new StarHotel("HTH06", "Seattle", "4 star", 160, "Normal", 4));
        hotelList2.add(new StarHotel("HTH07", "Austin", "5 star", 220, "Deluxe", 7));
        hotelList2.add(new StarHotel("HTH08", "Boston", "3 star", 90, "Normal", 3));
        hotelList2.add(new StarHotel("HTH09", "Denver", "4 star", 170, "Premium", 5));
        hotelList2.add(new StarHotel("HTH23", "Atlanta", "5 star", 210, "Deluxe", 9));

        // Merging both collections
        List<Hotel> mergedHotels = new ArrayList<>();
        mergedHotels.addAll(hotelList1);
        mergedHotels.addAll(hotelList2);

        // Sorting by hotel ID
        mergedHotels.sort(Comparator.comparing(Hotel::getHotelId));

        // Checking for hotel ID availability
        String searchId = "HTH23";
        boolean found = mergedHotels.stream().anyMatch(hotel -> hotel.getHotelId().equals(searchId));
        System.out.println("Hotel ID " + searchId + " available: " + found);

        // Displaying discounted costs
        for (Hotel hotel : mergedHotels) {
            System.out.println("Discounted Cost for " + hotel.getHotelId() + ": " + hotel.getDiscountedCost());
        }
    }

}
