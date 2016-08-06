<?php

function sales_recurring_display() {
	global $Ajax;
	
	display_heading(_("Recurring Order Details"));
	start_outer_table(TABLESTYLE2, "width='90%'");
	table_section(1);

	date_row(
		_("Start Date:"),
		'dt_from',
		_("Enter date this order starts")
	);
	date_row(
		_("End Date:"),
		'dt_to',
		_("Enter date this order ends")
	);
	check_row(_("Auto Create:"), 'auto');
	
	table_section(2);

	array_selector_row(_("Repeats:"), 'repeats', null,
		array('year' => _('Yearly'), 'month' => _('Monthly'), 'week' => _('Weekly')),
		array(
			'select_submit' => true,
			'async' => false // Force the whole body to redraw
		)
	);
	text_row(_("Every:"), 'every', null, 25, 25,
		_('How regularly to repeat the order')
	);
	switch (get_post('repeats')) {
		case 'year':
			date_row(
				_("On:"),
				'occur_year',
				_("Enter date on which this order should recur")
			);
			break;
		case 'month':
			text_row(_("On:"), 'occur_month', null, 25, 25,
				_('Enter date in month on which this order should recur')
			);
			break;
		case 'week':
			array_selector_row(_("On:"), 'occur_week', null,
				array(
					_('Monday'), _('Tuesday'), _('Wednesday'), _('Thursday'),
					_('Friday'), _('Saturday'), _('Sunday')
				)
			);
			break;
	}
	
	end_outer_table(1);

}