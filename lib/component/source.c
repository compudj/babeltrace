/*
 * source.c
 *
 * Babeltrace Source Component
 *
 * Copyright 2015 Jérémie Galarneau <jeremie.galarneau@efficios.com>
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

#include <babeltrace/ref.h>
#include <babeltrace/compiler.h>
#include <babeltrace/component/component-source-internal.h>
#include <babeltrace/component/component-internal.h>
#include <babeltrace/component/port-internal.h>
#include <babeltrace/component/notification/iterator.h>
#include <babeltrace/component/notification/iterator-internal.h>

BT_HIDDEN
enum bt_component_status bt_component_source_validate(
		struct bt_component *component)
{
	enum bt_component_status ret = BT_COMPONENT_STATUS_OK;

	if (!component) {
		ret = BT_COMPONENT_STATUS_INVALID;
		goto end;
	}

	if (!component->class) {
		ret = BT_COMPONENT_STATUS_INVALID;
		goto end;
	}

	if (component->class->type != BT_COMPONENT_CLASS_TYPE_SOURCE) {
		ret = BT_COMPONENT_STATUS_INVALID;
		goto end;
	}

end:
	return ret;
}

BT_HIDDEN
void bt_component_source_destroy(struct bt_component *component)
{
}

BT_HIDDEN
struct bt_component *bt_component_source_create(
		struct bt_component_class *class, struct bt_value *params)
{
	struct bt_component_source *source = NULL;

	source = g_new0(struct bt_component_source, 1);
	if (!source) {
		goto end;
	}

end:
	return source ? &source->parent : NULL;
}

BT_HIDDEN
struct bt_notification_iterator *bt_component_source_create_notification_iterator(
		struct bt_component *component)
{
	return bt_component_create_iterator(component, NULL);
}

BT_HIDDEN
struct bt_notification_iterator *bt_component_source_create_notification_iterator_with_init_method_data(
		struct bt_component *component, void *init_method_data)
{
	return bt_component_create_iterator(component, init_method_data);
}

enum bt_component_status bt_component_source_get_output_port_count(
		struct bt_component *component, uint64_t *count)
{
	enum bt_component_status status = BT_COMPONENT_STATUS_OK;

	if (!component || !count ||
			component->class->type != BT_COMPONENT_CLASS_TYPE_SOURCE) {
	        status = BT_COMPONENT_STATUS_INVALID;
		goto end;
	}

	*count = bt_component_get_output_port_count(component);
end:
	return status;
}

struct bt_port *bt_component_source_get_output_port(
		struct bt_component *component, const char *name)
{
	struct bt_port *port = NULL;

	if (!component || !name ||
			component->class->type != BT_COMPONENT_CLASS_TYPE_SOURCE) {
		goto end;
	}

	port = bt_component_get_output_port(component, name);
end:
	return port;
}

struct bt_port *bt_component_source_get_output_port_at_index(
		struct bt_component *component, int index)
{
	struct bt_port *port = NULL;

	if (!component ||
			component->class->type != BT_COMPONENT_CLASS_TYPE_SOURCE) {
		goto end;
	}

	port = bt_component_get_output_port_at_index(component, index);
end:
	return port;
}

struct bt_port *bt_component_source_get_default_output_port(
		struct bt_component *component)
{
	return bt_component_source_get_output_port(component,
			DEFAULT_OUTPUT_PORT_NAME);
}

struct bt_port *bt_component_source_add_output_port(
		struct bt_component *component, const char *name)
{
	struct bt_port *port = NULL;

	if (!component ||
			component->class->type != BT_COMPONENT_CLASS_TYPE_SOURCE) {
		goto end;
	}

	port = bt_component_add_output_port(component, name);
end:
	return port;
}
