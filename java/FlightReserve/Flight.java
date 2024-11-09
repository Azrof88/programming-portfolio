package FlightReserve;

abstract class Flight {
    protected String flightId;
    protected String routeId;
    protected String arrivalTime;
    protected String departureTime;
    protected double flightFare;
    protected String flightType;
    protected int availableSeats;

    public Flight(String flightId, String routeId, String arrivalTime, String departureTime, double flightFare,
            String flightType, int availableSeats) {
        this.flightId = flightId;
        this.routeId = routeId;
        this.arrivalTime = arrivalTime;
        this.departureTime = departureTime;
        this.flightFare = flightFare;
        this.flightType = flightType;
        this.availableSeats = availableSeats;
    }

    public abstract double calculateFare();

    public void bookTicket(int seats) {
        if (availableSeats >= seats) {
            availableSeats -= seats;
            System.out.println(seats + " ticket(s) booked successfully.");
        } else {
            System.out.println("Not enough available seats.");
        }
    }

    public void cancelTicket(int seats) {
        availableSeats += seats;
        System.out.println(seats + " ticket(s) cancelled successfully.");
    }

    public void displayDetails() {
        System.out.println("Flight ID: " + flightId + ", Route ID: " + routeId + ", Arrival: " + arrivalTime
                + ", Departure: " + departureTime + ", Fare: $" + flightFare + ", Type: " + flightType
                + ", Available Seats: " + availableSeats);
    }

}
