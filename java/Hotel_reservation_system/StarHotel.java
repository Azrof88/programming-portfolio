package Hotel_reservation_system;

public class StarHotel extends Hotel {
    public StarHotel(String hotelId, String location, String hotelType, double costPerRoom, String roomType,
            int totalRooms) {
        super(hotelId, location, hotelType, costPerRoom, roomType, totalRooms);
    }

    @Override
    public double getDiscountedCost() {
        if ("5 star".equals(getHotelType())) {
            return super.getDiscountedCost() * 0.8; // 20% discount
        } else if ("4 star".equals(getHotelType())) {
            return super.getDiscountedCost() * 0.85; // 15% discount
        } else {
            return super.getDiscountedCost(); // No discount for 3 star
        }
    }

}
