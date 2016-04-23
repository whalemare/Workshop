package ru.whalemare;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MainTest {

    final int[] array = {1, 2, 3, 4, 5};
    Main main;
    @Before
    public void setUp() throws Exception {
        main = new Main();
    }

    @After
    public void tearDown() throws Exception {

    }

    @Test
    public void testMain() throws Exception {
        testRightSum(9, array);
    }

    @Test
    public void testRightSum(int sum, int[] array){
        assertEquals(sum, main.getRightSum(array, 2));
    }

}