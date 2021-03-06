#ifndef BABELTRACE_PLUGIN_H
#define BABELTRACE_PLUGIN_H

/*
 * BabelTrace - Babeltrace Plug-in Interface
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

#ifdef __cplusplus
extern "C" {
#endif

struct bt_plugin;

/**
 * Get the name of a plug-in.
 *
 * @param plugin	An instance of a plug-in
 * @returns		Plug-in name or NULL on error
 */
extern const char *bt_plugin_get_name(struct bt_plugin *plugin);

/**
 * Get the name of a plug-in's author.
 *
 * @param plugin	An instance of a plug-in
 * @returns		Plug-in author or NULL on error
 */
extern const char *bt_plugin_get_author(struct bt_plugin *plugin);

/**
 * Get the license of a plug-in.
 *
 * @param plugin	An instance of a plug-in
 * @returns		Plug-in license or NULL on error
 */
extern const char *bt_plugin_get_license(struct bt_plugin *plugin);

/**
 * Get the decription of a plug-in.
 *
 * @param plugin	An instance of a plug-in
 * @returns		Plug-in description or NULL if none is available
 */
extern const char *bt_plugin_get_description(struct bt_plugin *plugin);

/**
 * Get the path of a plug-in.
 *
 * @param plugin	An instance of a plug-in
 * @returns		Plug-in path or NULL on error
 */
extern const char *bt_plugin_get_path(struct bt_plugin *plugin);

#ifdef __cplusplus
}
#endif

#endif /* BABELTRACE_PLUGIN_H */
