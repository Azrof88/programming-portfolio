package FlightReserve;

public class EmiratesAirlines extends Flight implements Airline {

    public EmiratesAirlines(String flightId, String routeId, String arrivalTime, String departureTime,
            double flightFare, String flightType, int availableSeats) {
        super(flightId, routeId, arrivalTime, departureTime, flightFare, flightType, availableSeats);
    }

    @Override
    public double calculateFare() {
        return flightFare - (flightFare * getDiscount(flightType));
    }

    @Override
    public double getDiscount(String classType) {
        switch (classType) {
            case "ECO":
                return 0.15;
            case "BUS":
                return 0.20;
            case "GEN":
                return 0.05;
            default:
                return 0;
        }
    }

}
