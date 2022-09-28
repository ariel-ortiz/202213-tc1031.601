#include <stdexcept>
#include "catch.h"
#include "queue.h"

TEST_CASE("test the Queue class")
{
    Queue<bool> a(0);

    Queue<int> b(4);
    b.enqueue(1);
    b.enqueue(2);
    b.enqueue(3);
    b.enqueue(4);

    Queue<std::string> c(10);
    c.enqueue("alpha");
    c.enqueue("beta");
    c.enqueue("gamma");
    c.enqueue("delta");
    c.enqueue("epsilon");
    c.enqueue("zeta");

    Queue<double> d(10);
    d.enqueue(1);
    d.enqueue(2.5);
    d.enqueue(-4.25);
    d.enqueue(10.75);
    d.enqueue(42);
    d.enqueue(0);
    d.enqueue(76.125);
    d.enqueue(-5.5);

    SECTION("test size") {
        REQUIRE(a.size() == 0);
        REQUIRE(b.size() == 4);
        REQUIRE(c.size() == 6);
        REQUIRE(d.size() == 8);
    }

    SECTION("test capacity") {
        REQUIRE(a.capacity() == 0);
        REQUIRE(b.capacity() == 4);
        REQUIRE(c.capacity() == 10);
        REQUIRE(d.capacity() == 10);
    }

    SECTION("test is_empty") {
        REQUIRE(a.is_empty());
        REQUIRE_FALSE(b.is_empty());
        REQUIRE_FALSE(c.is_empty());
        REQUIRE_FALSE(d.is_empty());
    }

    SECTION("test peek") {
        REQUIRE_THROWS_AS(a.peek(), std::underflow_error);
        REQUIRE(b.peek() == 1);
        REQUIRE(c.peek() == "alpha");
        REQUIRE(d.peek() == 1.0);
    }

    SECTION("test enqueue") {
        REQUIRE_THROWS_AS(a.enqueue(true), std::overflow_error);
        REQUIRE_THROWS_AS(b.enqueue(5), std::overflow_error);
        c.enqueue("eta");
        c.enqueue("theta");
        c.enqueue("iota");
        c.enqueue("kappa");
        REQUIRE_THROWS_AS(c.enqueue("lambda"), std::overflow_error);
        d.enqueue(3.1416);
        d.enqueue(2.7178);
        REQUIRE_THROWS_AS(d.enqueue(1.618), std::overflow_error);
    }

    SECTION("test dequeue") {
        REQUIRE_THROWS_AS(a.dequeue(), std::underflow_error);
        REQUIRE(b.dequeue() == 1);
        REQUIRE(b.size() == 3);
        REQUIRE(b.dequeue() == 2);
        REQUIRE(b.size() == 2);
        REQUIRE(b.dequeue() == 3);
        REQUIRE(b.size() == 1);
        REQUIRE(b.dequeue() == 4);
        REQUIRE(b.size() == 0);
        REQUIRE(b.is_empty());
        REQUIRE_THROWS_AS(b.dequeue(), std::underflow_error);
        REQUIRE(c.dequeue() == "alpha");
        REQUIRE(c.size() == 5);
        REQUIRE(c.dequeue() == "beta");
        REQUIRE(c.size() == 4);
        REQUIRE(c.dequeue() == "gamma");
        REQUIRE(c.size() == 3);
        REQUIRE(c.dequeue() == "delta");
        REQUIRE(c.size() == 2);
        REQUIRE(c.dequeue() == "epsilon");
        REQUIRE(c.size() == 1);
        REQUIRE(c.dequeue() == "zeta");
        REQUIRE(c.size() == 0);
        REQUIRE(c.is_empty());
        REQUIRE_THROWS_AS(c.dequeue(), std::underflow_error);
        REQUIRE(d.dequeue() == 1.0);
        REQUIRE(d.size() == 7);
        REQUIRE(d.dequeue() == 2.5);
        REQUIRE(d.size() == 6);
        REQUIRE(d.dequeue() == -4.25);
        REQUIRE(d.size() == 5);
        REQUIRE(d.dequeue() == 10.75);
        REQUIRE(d.size() == 4);
        REQUIRE(d.dequeue() == 42.0);
        REQUIRE(d.size() == 3);
        REQUIRE(d.dequeue() == 0.0);
        REQUIRE(d.size() == 2);
        REQUIRE(d.dequeue() == 76.125);
        REQUIRE(d.size() == 1);
        REQUIRE(d.dequeue() == -5.5);
        REQUIRE(d.size() == 0);
        REQUIRE(d.is_empty());
        REQUIRE_THROWS_AS(d.dequeue(), std::underflow_error);
    }

    SECTION("test clear") {
        a.clear();
        REQUIRE(a.size() == 0);
        REQUIRE(a.is_empty());
        b.clear();
        REQUIRE(b.size() == 0);
        REQUIRE(b.is_empty());
        c.clear();
        REQUIRE(c.size() == 0);
        REQUIRE(c.is_empty());
        d.clear();
        REQUIRE(d.size() == 0);
        REQUIRE(d.is_empty());
    }

    SECTION("test circularity") {
        b.clear();
        for (int i = 0; i < 100; ++i) {
            b.enqueue(42);
            REQUIRE(b.size() == 1);
            REQUIRE(b.peek() == 42);
            REQUIRE(b.dequeue() == 42);
            REQUIRE(b.is_empty());
        }
        c.clear();
        for (int i = 0; i < 100; ++i) {
            c.enqueue("mu");
            c.enqueue("nu");
            c.enqueue("xi");
            REQUIRE(c.size() == 3);
            REQUIRE(c.peek() == "mu");
            REQUIRE(c.dequeue() == "mu");
            REQUIRE(c.size() == 2);
            REQUIRE(c.peek() == "nu");
            REQUIRE(c.dequeue() == "nu");
            REQUIRE(c.size() == 1);
            REQUIRE(c.peek() == "xi");
            REQUIRE(c.dequeue() == "xi");
            REQUIRE(c.size() == 0);
        }
        d.clear();
        for (int i = 0; i < 100; ++i) {
            if (i < 10) {
                d.enqueue(i);
                REQUIRE(d.size() == i + 1);
            } else {
                REQUIRE(d.peek() == i - 10);
                REQUIRE(d.dequeue() == i - 10);
                if (i < 90) {
                    d.enqueue(i);
                    REQUIRE(d.size() == 10);
                } else {
                    REQUIRE(d.size() == 99 - i);
                }
            }
        }
        REQUIRE(d.is_empty());
    }
}
