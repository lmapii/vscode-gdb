#include "dummy.h"
#include "mockme.h"

/**
 * structure holding items for dynamic/runtime re-configuration using XCP
 */
typedef struct
{
    boolean do_reconfigure;
    /**< is set to TRUE for re-configuration */
    uint8 counter;
    /**< a simple counter increased when do_reconfigure is TRUE */
} t_dummy_ctrl;

static t_dummy_ctrl dummy_ctrl;
static boolean dummy_is_initialized = FALSE;

void dummy_init (void)
{
    dummy_ctrl.do_reconfigure = FALSE;
    dummy_ctrl.counter = 0;
    dummy_is_initialized = TRUE;

    mockme_init ();
}

void dummy_periodic (void)
{
    if (!dummy_is_initialized)
    {
        dummy_init ();
    }

    /**
     * \trace{NEW_IN_DOC_[ID-of-UDD]}
     * The template module **shall** include an example for executing an action via XCP.
     * \endtrace
     */
    if (dummy_ctrl.do_reconfigure)
    {
        dummy_ctrl.counter += 1;
        dummy_ctrl.do_reconfigure = FALSE;
    }
}