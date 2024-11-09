package FlightReserve;

public class AmericanAirlines extends Flight {

    public AmericanAirlines(String flightId, String routeId, String arrivalTime, String departureTime,
            double flightFare, String flightType, int availableSeats) {
        super(flightId, routeId, arrivalTime, departureTime, flightFare, flightType, availableSeats);
    }

    @Override
    public double calculateFare() {
        return flightFare; // No discount
    }

}
