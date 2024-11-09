package FlightReserve;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Flight> flights1 = new ArrayList<>();
        List<Flight> flights2 = new ArrayList<>();

        flights1.add(new EmiratesAirlines("F121", "IND111", "12:00", "18:00", 300, "ECO", 21));
        flights1.add(new QatarAirlines("F122", "IND112", "13:00", "19:00", 350, "BUS", 15));
        flights1.add(new AmericanAirlines("F123", "IND113", "14:00", "20:00", 400, "GEN", 10));
        flights1.add(new EmiratesAirlines("F124", "IND114", "15:00", "21:00", 450, "ECO", 5));
        flights1.add(new QatarAirlines("F125", "IND115", "16:00", "22:00", 500, "BUS", 8));

        flights2.add(new AmericanAirlines("F126", "IND116", "17:00", "23:00", 600, "GEN", 12));
        flights2.add(new EmiratesAirlines("F127", "IND117", "18:00", "24:00", 350, "ECO", 20));
        flights2.add(new QatarAirlines("F128", "IND118", "19:00", "01:00", 370, "BUS", 18));
        flights2.add(new AmericanAirlines("F129", "IND119", "20:00", "02:00", 410, "GEN", 14));
        flights2.add(new EmiratesAirlines("F130", "IND120", "21:00", "03:00", 450, "ECO", 9));

        List<Flight> allFlights = new ArrayList<>(flights1);
        allFlights.addAll(flights2);

        Flight searchFlight = new EmiratesAirlines("F121", "IND111", "12:00", "18:00", 300, "ECO", 21);
        boolean contains = allFlights.stream().anyMatch(flight -> flight.flightId.equals(searchFlight.flightId));

        System.out.println("Collection contains the flight: " + contains);

    }

}
