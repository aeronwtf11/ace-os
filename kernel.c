void aceos_main(void) {
    volatile char *video = (volatile char *)0xB8000;
    video[0] = 'A';
    video[1] = 0x0F;
}