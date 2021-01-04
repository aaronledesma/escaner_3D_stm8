#ifndef _ENGINE_BY_STEPS_H_
  #define _ENGINE_BY_STEPS_H_

  #define EBS_CLOCKWISE         ((unsigned char)(1))
  #define EBS_COUNTERCLOCKWISE  ((unsigned char)(0))
  #define EBS_STEPS             ((unsigned char)(4))

  void EBS_Move(unsigned char clockwise);
  void EBS_Init(void);
  void EBS_Move2(unsigned char clockwise, unsigned char reduction);

#endif
