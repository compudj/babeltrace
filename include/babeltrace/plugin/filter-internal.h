#ifndef BABELTRACE_PLUGIN_FILTER_INTERNAL_H
#define BABELTRACE_PLUGIN_FILTER_INTERNAL_H

/*
 * BabelTrace - Filter Component Internal
 *
 * Copyright 2016 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Author: Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <babeltrace/babeltrace-internal.h>
#include <babeltrace/plugin/component-internal.h>
#include <babeltrace/plugin/component-class-internal.h>
#include <babeltrace/plugin/plugin-system.h>
#include <babeltrace/plugin/input.h>

struct bt_value;

struct bt_component_filter_class {
	struct bt_component_class parent;
};

struct bt_component_filter {
	struct bt_component parent;
	bt_component_filter_init_iterator_cb init_iterator;
	bt_component_sink_add_iterator_cb add_iterator;
	struct component_input input;
};

/**
 * Allocate a filter component.
 *
 * @param class			Component class
 * @param params		A dictionary of component parameters
 * @returns			A filter component instance
 */
BT_HIDDEN
struct bt_component *bt_component_filter_create(
		struct bt_component_class *class, struct bt_value *params);

/**
 * Validate a filter component.
 *
 * @param component		Filter component instance to validate
 * @returns			One of #bt_component_status
 */
BT_HIDDEN
enum bt_component_status bt_component_filter_validate(
		struct bt_component *component);

#endif /* BABELTRACE_PLUGIN_FILTER_INTERNAL_H */
