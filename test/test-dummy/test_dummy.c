
#include "std_types.h"
#include "dummy.h"

void setUp (void) {}

void tearDown (void) {}

static volatile uint8 _dummy_i = 0;

int main (void)
{
    dummy_init ();
    _dummy_i ++;
    dummy_periodic ();
    _dummy_i ++;
}
