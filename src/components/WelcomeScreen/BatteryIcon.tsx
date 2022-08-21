import { memo, SVGProps } from 'react';
 
const BatteryIcon = (props: SVGProps<SVGSVGElement>) => (
  <svg preserveAspectRatio='none' viewBox='0 0 26 14' fill='none' xmlns='http://www.w3.org/2000/svg' {...props}>
    <rect opacity={0.35} x={1.33325} y={1.33331} width={22} height={11.3333} rx={2.66667} stroke='white' />
    <path
      opacity={0.4}
      d='M24.3333 4.99998V8.99998C25.138 8.6612 25.6613 7.87311 25.6613 6.99998C25.6613 6.12685 25.138 5.33876 24.3333 4.99998'
      fill='white'
    />
    <rect x={3.33325} y={3.33331} width={18} height={7.33333} rx={1.33333} fill='white' />
  </svg>
);
 
const Memo = memo(BatteryIcon);
export { Memo as BatteryIcon };