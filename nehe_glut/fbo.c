//
// frame buffer object
// kongque
// 04/15/2011
#include <GL/gl.h>

enum { kColor, kDepth, kNumRenderBuffer };
GLuint framebuffer, renderbuffer[kNumRenderBuffer];

void init()
{
	glGenRenderbuffers(kNumRenderBuffer, renderbuffer);
	// bind color buffer
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer[kColor]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA, 256, 256);

	// bind depth buffer
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer[kDepth]);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, 256, 256);

	// generate frame buffer
	glGenFramebuffers(1, &framebuffer);
	// glBindFramebuffer的target参数指定一个缓冲区对象用于读取或写入。当target是GL_DRAW_FRAMEBUFFER的时候，framebuffer指定了帧缓冲区渲染的目标。当target为GL_READ_FRAMEBUFFER的时候，framebuffer指定了读取操作的源。
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, renderbuffer[kColor]);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, renderbuffer[kDepth]);
	glEnable(GL_DEPTH_TEST);
}
}
