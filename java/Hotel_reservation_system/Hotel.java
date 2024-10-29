package Hotel_reservation_system;

public class Hotel {
    private String hotelId;
    private String location;
    private String hotelType;
    private double costPerRoom;
    private String roomType;
    private int totalRooms;
    private int availableRooms;

    public Hotel(String hotelId, String location, String hotelType, double costPerRoom, String roomType,
            int totalRooms) {
        this.hotelId = hotelId;
        this.location = location;
        this.hotelType = hotelType;
        this.costPerRoom = costPerRoom;
        this.roomType = roomType;
        this.totalRooms = totalRooms;
        this.availableRooms = totalRooms; // Initially, all rooms are available
    }

    public void bookRoom() {
        if (availableRooms > 0) {
            availableRooms--;
            System.out.println("Room booked successfully.");
        } else {
            System.out.println("No rooms available.");
        }
    }

    public void cancelBooking() {
        if (availableRooms < totalRooms) {
            availableRooms++;
            System.out.println("Booking cancelled successfully.");
        } else {
            System.out.println("No bookings to cancel.");
        }
    }

    public void displayDetails() {
        System.out.println("Hotel ID: " + hotelId);
        System.out.println("Location: " + location);
        System.out.println("Hotel Type: " + hotelType);
        System.out.println("Cost per Room: " + costPerRoom);
        System.out.println("Room Type: " + roomType);
        System.out.println("Total Rooms: " + totalRooms);
        System.out.println("Available Rooms: " + availableRooms);
    }

    public double getDiscountedCost() {
        return costPerRoom; // No discount by default
    }

    public String getHotelId() {
        return hotelId;
    }

    public String getHotelType() {
        return hotelType; // Added getter for hotelType
    }

}
