import org.junit.Test;
import org.junit.jupiter.api.Assertions;

public class Testing {
    Storage main = new Storage();
    InvalidStorageUnitsSizeException exception = new InvalidStorageUnitsSizeException();

    @Test
    public void does_getUnitInStorage_return_storage_units() {
        int expected = 0;
        int actual = main.getUnitsInStorage();

        Assertions.assertEquals(expected, actual);
    }

    @Test
    public void does_addStorageUnits_add_storage_units() {
        int x = 1;
        main.addStorageUnits(x);

        int expected = 1;
        int actual = main.getUnitsInStorage();

        Assertions.assertEquals(expected, actual);
    }

    @Test
    public void does_removeUnitsFromStorage_remove_storage_units() {
        int x = 2;
        main.addStorageUnits(x);
        x = 1;
        main.removeUnitsFromStorage(1);

        int expected = 1;
        int actual = main.getUnitsInStorage();

        Assertions.assertEquals(expected, actual);
    }
}