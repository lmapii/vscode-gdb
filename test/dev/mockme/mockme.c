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
} t_mockme_ctrl;

static uint8 mockme_internal_data;
static t_mockme_ctrl mockme_ctrl;
static boolean mockme_is_initialized = FALSE;

void mockme_init (void)
{
    mockme_ctrl.do_reconfigure = FALSE;
    mockme_ctrl.counter = 0;
    mockme_is_initialized = TRUE;
}

void mockme_periodic (void)
{
    if (!mockme_is_initialized)
    {
        mockme_init ();
    }

    /**
     * \trace{NEW_IN_DOC_[ID-of-UDD]}
     * The template module **shall** include an example for executing an action via XCP.
     * \endtrace
     */
    if (mockme_ctrl.do_reconfigure)
    {
        mockme_ctrl.counter += 1;
        mockme_ctrl.do_reconfigure = FALSE;
    }
}