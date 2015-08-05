/*
 * (C) Copyright 2015 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __KMS_WEBRTC_SESSION_H__
#define __KMS_WEBRTC_SESSION_H__

#include <gst/gst.h>
#include <commons/kmsbasertpsession.h>
#include "kmsicecandidate.h"

G_BEGIN_DECLS

typedef struct _KmsIRtpSessionManager KmsIRtpSessionManager;

/* #defines don't like whitespacey bits */
#define KMS_TYPE_WEBRTC_SESSION \
  (kms_webrtc_session_get_type())
#define KMS_WEBRTC_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_WEBRTC_SESSION,KmsWebrtcSession))
#define KMS_WEBRTC_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_WEBRTC_SESSION,KmsWebrtcSessionClass))
#define KMS_IS_WEBRTC_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_WEBRTC_SESSION))
#define KMS_IS_WEBRTC_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_WEBRTC_SESSION))
#define KMS_WEBRTC_SESSION_CAST(obj) ((KmsWebrtcSession*)(obj))

typedef struct _KmsWebrtcSession KmsWebrtcSession;
typedef struct _KmsWebrtcSessionClass KmsWebrtcSessionClass;

struct _KmsWebrtcSession
{
  KmsBaseRtpSession parent;

  NiceAgent *agent;
  GSList *remote_candidates;
};

struct _KmsWebrtcSessionClass
{
  KmsBaseRtpSessionClass parent_class;

  /* private */
  /* virtual methods */
  void (*post_constructor) (KmsWebrtcSession * self, KmsBaseSdpEndpoint * ep,
			    guint id, KmsIRtpSessionManager * manager, GMainContext * context);
};

GType kms_webrtc_session_get_type (void);

KmsWebrtcSession * kms_webrtc_session_new (KmsBaseSdpEndpoint * ep, guint id,
					   KmsIRtpSessionManager * manager, GMainContext * context);

G_END_DECLS
#endif /* __KMS_WEBRTC_SESSION_H__ */
