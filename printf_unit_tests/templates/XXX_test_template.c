#include "libunit.h"
#include "tests.h"
#include <string.h>
#include <stdlib.h>

# define ARGS TMPL_ARGS

int		TMPL_FCT_NAME_TMPL_TEST_FCT_NAME(void)
{
	t_result	*result;
	int			pfd[2];
	int			save_out;
	int			comp;
	int			err;
	int			fd_trace;

	str = NULL;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	if ((err = pipe_stdout(pfd, &save_out)))
		return (err);
	result.ref_ret = printf(ARGS);
	if ((err = read_pipe(&result.ref_str, &ret, pfd, &save_out)))
		return (err);
	if ((err = pipe_stdout(pfd, &save_out)))
		return (err);
	result.user_ret = ft_printf(ARGS);
	if ((err = read_pipe(&result.user_str, &ret, pfd, &save_out)))
		return (err);
	if ((mresult.user_ret != result.ref_ret)
			|| memcmp(result.user_str, result.ref_str, result.ref_ret))
	{
		print_test_result_values_trace(result, fd_trace);
		free_result(result);
		return (-1);
	}
	else
		return (0);
}
