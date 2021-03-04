import org.junit.Test;
import org.junit.jupiter.api.Assertions;

public class test_main {
    Main main = new Main();
    @Test
    public void is_Fishy_returning_fish() {
        Assertions.assertEquals("Fish", main.Fishy());
    }

}
